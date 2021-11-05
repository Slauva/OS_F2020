link ../week01/file.txt _ex2.txt
find ../week01/file.txt -inum 5012985
find .. -inum 5012985 -exec rm {} \; 