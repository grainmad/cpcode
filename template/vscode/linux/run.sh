#! /usr/bin/bash

# you need set environment variable ws="/root/cpcode" as workspace dir

if [ -z "${ws}" ]
then
        echo you need set environment variable ws
        exit 1
fi

if [ -z "`which g++`" ]
then
        echo you need install g++
        exit 2
fi

program="${ws}/a.out"
input="${ws}/in.txt"


if [ "$#" -eq 1 -a -e "$1" ]
then
        echo = = = = = = = = = = = = = ${1} output = = = = = = = = = = = = =
        g++ -std=c++17 $1 -o ${program}
        ${program} < ${input}
else
        echo Only requires a cpp file as parameter
fi