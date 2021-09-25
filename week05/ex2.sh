#!/bin/bash
file="./text.txt"

while :
do
	if ln "$file" "$file.lock" > "/dev/null" 2>&1
	then
		prev="$(cat "$file" | tail -1)"
		new=$((prev+1))

		echo "$new" >> "$file"
		echo "$new"

		rm "$file.lock"
	fi
done