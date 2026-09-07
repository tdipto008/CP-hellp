#!/bin/bash
set -e

# ==============================================
#  Competitive Programming Assistant Installer
# ==============================================

# -------- Paths --------
INSTALL_PATH="/usr/local/bin"
SCRIPT_NAME="CPA"
CPA_DIR="$HOME/.CPA"
TEMP_DIR=$(mktemp -d)
REPO_URL="https://github.com/tdipto008/Competetive-Programming-Automation"

# -------- Colors --------
C_OK="\033[0;32m"
C_ERR="\033[1;31m"
C_INFO="\033[1;36m"
C_WARN="\033[0;33m"
C_RST="\033[0m"

# ==============================================
# Cleanup on exit
# ==============================================
cleanup() {
  rm -rf "$TEMP_DIR"
}
trap cleanup EXIT

# ==============================================
# Download Repository
# ==============================================
download_repo() {
  echo -e "${C_INFO}  Downloading Competitive-Programming-Assistant:${C_RST}"
  cd "${TEMP_DIR}"
  git clone --depth 1 -q "$REPO_URL" CPA
  cd CPA
  echo -e "   [${C_OK}✓${C_RST}] Downloaded repository"
}

# ==============================================
# Dependency Check
# ==============================================
check_dependencies() {
  echo -e "$C_INFO  Checking dependencies:$C_RST"

  local deps=(g++ gcc git jq nc curl)
  local missing=()

  for dep in "${deps[@]}"; do
    if command -v "$dep" &>/dev/null; then
      echo -e "   [${C_OK}✓${C_RST}] $dep"
    else
      echo -e "   [${C_ERR}✗${C_RST}] $dep (missing)"
      missing+=("$dep")
    fi
  done

  if [ ${#missing[@]} -ne 0 ]; then
    echo -e "${C_ERR}  Installation failed:${C_RST} Install the missing dependencies and re-run the command"
    exit 1
  fi
}

# ==============================================
# Install CPA Files
# ==============================================
install_files() {
  echo -e "${C_INFO}  Installing Competitive-Programming-Assistant:${C_RST}"

  local REPO_DIR="$TEMP_DIR/CPA"
  mkdir -p "$CPA_DIR/checkers"

  cp "$REPO_DIR/debug.h"   "$CPA_DIR/"
  cp "$REPO_DIR/testlib.h" "$CPA_DIR/"
  cp -r "$REPO_DIR/checkers/"* "$CPA_DIR/checkers/"

  sudo install -m 755 "$REPO_DIR/CPA.sh" "$INSTALL_PATH/$SCRIPT_NAME"

  echo -e "   [${C_OK}✓${C_RST}] Installed headers to $CPA_DIR"
  echo -e "   [${C_OK}✓${C_RST}] Installed checkers to $CPA_DIR/checkers"
  echo -e "   [${C_OK}✓${C_RST}] Installed CPA script to $INSTALL_PATH/$SCRIPT_NAME"
}

# ==============================================
# Main
# ==============================================
check_dependencies
download_repo
install_files

echo -e "$C_OK󰄲  Installation successful:$C_RST Run ${C_WARN}CPA --help${C_RST} to get started!!"