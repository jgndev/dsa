#!/usr/bin/env bash

set -euo pipefail
IFS=$'\n\t'

# Constants
readonly SCRIPT_NAME="${0##*/}"
readonly BUILD_DIR="build"

# Color codes for output
readonly RED='\033[0;31m'
readonly GREEN='\033[0;32m'
readonly NC='\033[0m' # No Color

# Function to print error messages
print_error() {
  printf "${RED}Error: %s${NC}\n" "$1" >&2
}

# Function to print success messages
print_success() {
  printf "${GREEN}Success: %s${NC}\n" "$1"
}

# Function to check if a command exists
command_exists() {
  command -v "$1" &>/dev/null
}

# Main function
main() {
  # Check if CMake is installed
  if ! command_exists cmake; then
    print_error "CMake is not installed. Please install CMake and try again."
    exit 1
  fi

  # Create build directory if it doesn't exist
  mkdir -p "${BUILD_DIR}"

  # Generate build files and compile_commands.json
  echo "Generating build files and compile_commands.json..."
  if ! cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -B "${BUILD_DIR}" .; then
    print_error "Failed to generate build files."
    exit 1
  fi
  print_success "Build files and compile_commands.json generated."

  # Build the project
  echo "Building the project..."
  if ! cmake --build "${BUILD_DIR}"; then
    print_error "Failed to build the project."
    exit 1
  fi
  print_success "Project built successfully."

  # Symlink compile_commands.json to project root
  echo "Creating symlink for compile_commands.json..."
  if [[ -L compile_commands.json ]]; then
    rm compile_commands.json
  elif [[ -e compile_commands.json ]]; then
    print_error "A file named compile_commands.json already exists and is not a symlink."
    exit 1
  fi
  if ! ln -s "${BUILD_DIR}/compile_commands.json" .; then
    print_error "Failed to create symlink for compile_commands.json."
    exit 1
  fi
  print_success "Symlink for compile_commands.json created in project root."

  echo "All tasks completed successfully!"
  echo "You can now use compile_commands.json for your LSP."
}

# Execute main function
main "$@"
