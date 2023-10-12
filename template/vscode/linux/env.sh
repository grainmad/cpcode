# first set environment variable ws="/root/cpcode" as your workspace dir
# then source env.shi

if [ -z "${ws}" ]
then
        echo you need set environment variable ws
        exit 1
fi

if test -z "`which python`" -a -z "`which python3`"
then
        echo can not find python
        exit 2
fi

py=`which python`

# echo $py

echo ${py:=`which python3`} > /dev/null

# echo $py

alias atcode_gen_sol="(cd ${ws} && ${py} atcode/contest/atcode_gen_sol.py)"
alias cf_gen_sol="(cd ${ws} && ${py} cf/contest/cf_gen_sol.py)"
alias ape="(cd ${ws} && ${py} cf/a-problem-everyday/gen-problem.py)"
alias run="${ws}/template/vscode/linux/run.sh"
alias hexo_deploy="(cd ${ws} && ${py} hexo-deployer.py)"