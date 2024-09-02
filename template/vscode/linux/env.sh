# ~/.bashrc append below
# export cpcode_ws="/home/xxx/cpcode"
# source ${cpcode_ws}/template/vscode/linux/env.sh


if [ -z "${cpcode_ws}" ]
then
        echo you need set environment variable cpcode_ws
        exit 1
fi


py=`which python`

# echo $py

echo ${py:=`which python`} > /dev/null

# echo $py

alias atcode_gen_sol="(cd ${cpcode_ws} && ${py} atcode/contest/atcode_gen_sol.py)"
alias cf_gen_sol="(cd ${cpcode_ws} && ${py} cf/contest/cf_gen_sol.py)"
alias ape="(cd ${cpcode_ws} && ${py} cf/a-problem-everyday/gen-problem.py)"
alias run="${cpcode_ws}/template/vscode/linux/run.sh"
alias lcmd="${cpcode_ws}/leetcode/lcmd.sh"
alias tbo="${cpcode_ws}/template/vscode/linux/test-bf-opt.sh"
alias hexo_deploy="(cd ${cpcode_ws} && ${py} hexo-deployer.py)"
