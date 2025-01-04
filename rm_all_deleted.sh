#!/bin/bash
set -eu

for fname in $(git status | grep "deleted" | awk -F":" '{ print $2 }'); do
    echo "git rm $fname" && git rm "$fname"
done
