#!/bin/bash

# argument is provided
if [ -z "$1" ]; then
    echo "Error: No problems string provided."
    exit 1
fi

# commit message
problems_string="Added exercises [$1]"

# github
git add . &&
git commit -m "$problems_string" &&
git push