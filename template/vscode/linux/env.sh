# ~/.bashrc append below
# export ws="/home/grainmad/cpcode"
# source ${ws}/template/vscode/linux/env.sh

if [ -z "${ws}" ]
then
        echo you need set environment variable ws
        exit 1
fi


py=`which python3`

# echo $py

echo ${py:=`which python3`} > /dev/null

# echo $py

alias atcode_gen_sol="(cd ${ws} && ${py} atcode/contest/atcode_gen_sol.py)"
alias cf_gen_sol="(cd ${ws} && ${py} cf/contest/cf_gen_sol.py)"
alias ape="(cd ${ws} && ${py} cf/a-problem-everyday/gen-problem.py)"
alias run="${ws}/template/vscode/linux/run.sh"
alias tbo="${ws}/template/vscode/linux/test-bf-opt.sh"
alias hexo_deploy="(cd ${ws} && ${py} hexo-deployer.py)"
