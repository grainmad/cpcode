# !/bin/bash

if test $# -ne 3
then
    echo "please input source files of data generator, brute force algorithm, and optimization algorithm"
    exit 0
fi

dataexc="${1}.exc"

bfexc="${2}.exc"

optexc="${3}.exc"

datatxt="${1}.txt"

bftxt="${2}.txt"

opttxt="${3}.txt"


g++ -std=c++17 $1 -o ${dataexc}

if test "$?" -ne 0
then
    exit 1
fi

g++ -std=c++17 $2 -o ${bfexc}

if test "$?" -ne 0
then
    exit 2
fi

g++ -std=c++17 $3 -o ${optexc}

if test "$?" -ne 0
then
    exit 3
fi




tc=1

while test 1 -eq 1
do
    ./${dataexc} > ${datatxt}

    cat ${datatxt} | ./${bfexc} > ${bftxt}

    cat ${datatxt} | ./${optexc} > ${opttxt}

    diff ${bftxt} ${opttxt}

    if test "$?" -eq 0
    then
        echo "Accepted ${tc}"
        ((++tc))
    else
        exit 0
    fi
done


