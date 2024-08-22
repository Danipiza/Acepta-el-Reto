#!/bin/bash


problems_string="Added exercises ["

# Loop through each variable and concatenate it to the string
for var in "$@"
do
    problems_string="$problems_string$var, "
done

# remove last char
problems_string="${problems_string::-2}"
problems_string="$problems_string]"


git add . &&
git commit -m "$problems_string" &&
git push
