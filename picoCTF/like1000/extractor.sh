#!/bin/sh

# Start with the initial tar file
tar_file="1000.tar"

while [[ "$tar_file" =~ [0-9]+\.tar ]]; do
    echo "Extacting $tar_file..."

    # Extract the tar file
    tar -xf $tar_file
    rm -f "$tar_file"

    tar_file=$(find . -maxdepth 1 -type f -name "*.tar" | grep -Eo '[0-9]+\.tar' | sort -nr | head -n1)

    if [[ -z "$tar_file" ]]; then
        echo "Extraction complete."
        break
    fi
done
