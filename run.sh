#!/bin/bash

set -e

echo "======================================"
echo "        Running Example Project        "
echo "======================================"

# Ensure JSON dependency exists
if ! dpkg -s nlohmann-json3-dev >/dev/null 2>&1; then
    echo "Installing nlohmann-json3-dev..."
    sudo apt update
    sudo apt install -y nlohmann-json3-dev
fi

# Verify /etc/example_data.txt exists
if [ ! -f /etc/example_data.txt ]; then
    echo "/etc/example_data.txt missing — creating default file..."
    sudo tee /etc/example_data.txt >/dev/null <<EOF2
ENGINE_STATUS=ACTIVE
SPEED_LIMIT=120
VEHICLE_ID=XE-2025
EOF2
fi

# Build Project
echo "Configuring CMake..."
cmake -B build

echo "Building project..."
cmake --build build

echo "Running executable..."
./build/example_reader
