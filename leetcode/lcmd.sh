#! /bin/bash


if [ "$#" -eq 1 ]
then
    ssh six0@six0 "cd contest/lcmd && python3 leecode-problem-md.py $1"
    scp six0@six0:~/contest/lcmd/*.md .
    ssh six0@six0 "rm ~/contest/lcmd/*.md"
else
    echo need slug or link contains slug
fi
