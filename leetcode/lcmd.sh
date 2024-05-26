#! /bin/bash


if [ "$#" -eq 1 ]
then
    wget --content-disposition "http://localhost:1760/file?link=$1"
else
    echo need slug or link contains slug
fi
