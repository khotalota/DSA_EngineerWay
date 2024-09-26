{
  description = "Robust C Program Build with Multiple Directories";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
        
        name = "main";
        
        buildInputs = with pkgs; [
          clang
        ];

        # Function to recursively find all .c files
        findSourceFiles = dir:
          let
            contents = builtins.readDir dir;
            handleEntry = name: type:
              if type == "directory" then
                findSourceFiles "${dir}/${name}"
              else if type == "regular" && pkgs.lib.hasSuffix ".c" name then
                [ "${dir}/${name}" ]
              else
                [ ];
          in
            pkgs.lib.concatLists (pkgs.lib.mapAttrsToList handleEntry contents);

        # Find all source files
        sourceFiles = findSourceFiles ./.;

        # Find all directories containing .h files
        headerDirs = pkgs.lib.filter (x: x != null) (
          pkgs.lib.mapAttrsToList
            (name: type: if type == "directory" && builtins.pathExists (./${name}) then name else null)
            (builtins.readDir ./.)
        );

        # Create -I flags for each header directory
        headerFlags = pkgs.lib.concatMapStrings (dir: "-I./${dir} ") headerDirs;

      in
      {
        packages.default = pkgs.stdenv.mkDerivation {
          inherit name buildInputs;
          
          src = ./.;
          
          buildPhase = ''
            echo "Source files found: ${builtins.toString sourceFiles}"
            echo "Header directories found: ${builtins.toString headerDirs}"
            echo "Header flags: ${headerFlags}"
            
            mkdir -p $out/bin
            ${pkgs.clang}/bin/clang -Wall -Wextra -pedantic \
              ${headerFlags} \
              ${builtins.concatStringsSep " " sourceFiles} \
              -o $out/bin/main
          '';

          installPhase = ''
            echo "Build Success!"
          '';
        };

        devShells.default = pkgs.mkShell {
          inherit buildInputs;
          
          shellHook = ''
            echo "Entering the development environment for ${name}"
          '';
        };
      }
    );
}
