#!/usr/bin/env bash
# compile and run cpp file, optionally with input file and expected output verification
#
# Usage:
#   cr <cpp>                         compile and run
#   cr <cpp> -i <input>              compile, run with input file
#   cr <cpp> -i <input> -o <output>  compile, run with input, diff against expected output
#   cr <cpp> -o <output>             compile, run (no input), diff against expected output

set -euo pipefail

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
CYAN='\033[0;36m'
BOLD='\033[1m'
RESET='\033[0m'

usage() {
    echo "Usage: cr <cpp_file> [-i <input_file>] [-o <expected_output_file>]"
    echo ""
    echo "Options:"
    echo "  -i <file>  input file to feed to the program via stdin"
    echo "  -o <file>  expected output file, diff against actual output"
    echo "  -h         show this help"
    exit 0
}

# --- parse args ---
if [ $# -lt 1 ]; then
    usage
fi

CPP_FILE=""
INPUT_FILE=""
EXPECT_FILE=""

while [ $# -gt 0 ]; do
    case "$1" in
        -h|--help)
            usage
            ;;
        -i)
            shift
            INPUT_FILE="$1"
            ;;
        -o)
            shift
            EXPECT_FILE="$1"
            ;;
        *)
            if [ -z "$CPP_FILE" ]; then
                CPP_FILE="$1"
            else
                echo -e "${RED}Error: unexpected argument '$1'${RESET}"
                usage
            fi
            ;;
    esac
    shift
done

# --- validate cpp file ---
if [ -z "$CPP_FILE" ]; then
    echo -e "${RED}Error: no cpp file specified${RESET}"
    usage
fi

if [ ! -f "$CPP_FILE" ]; then
    echo -e "${RED}Error: file '$CPP_FILE' not found${RESET}"
    exit 1
fi

if [ -n "$INPUT_FILE" ] && [ ! -f "$INPUT_FILE" ]; then
    echo -e "${RED}Error: input file '$INPUT_FILE' not found${RESET}"
    exit 1
fi

if [ -n "$EXPECT_FILE" ] && [ ! -f "$EXPECT_FILE" ]; then
    echo -e "${RED}Error: expected output file '$EXPECT_FILE' not found${RESET}"
    exit 1
fi

# --- compile ---
EXE_FILE="${CPP_FILE%.cpp}.out"

echo -e "${CYAN}${BOLD}[COMPILE]${RESET} g++ -std=c++17 ${CPP_FILE} -o ${EXE_FILE}"

if ! g++ -std=c++17 "$CPP_FILE" -o "$EXE_FILE" 2>&1; then
    echo -e "${RED}${BOLD}[FAILED]${RESET} compilation error"
    exit 1
fi

echo -e "${GREEN}${BOLD}[OK]${RESET} compiled successfully"
echo ""

# --- run ---
echo -e "${CYAN}${BOLD}[RUN]${RESET} ./${EXE_FILE}"

if [ -n "$INPUT_FILE" ]; then
    echo -e "${YELLOW}  input: ${INPUT_FILE}${RESET}"
fi

START_TIME=$(python3 -c 'import time; print(time.time())')

if [ -n "$INPUT_FILE" ]; then
    ACTUAL_OUTPUT=$("$EXE_FILE" < "$INPUT_FILE" 2>&1)
else
    ACTUAL_OUTPUT=$("$EXE_FILE" 2>&1)
fi

END_TIME=$(python3 -c 'import time; print(time.time())')
ELAPSED=$(python3 -c "print(f'{($END_TIME - $START_TIME)*1000:.1f}')")

EXIT_CODE=$?
echo ""

if [ $EXIT_CODE -ne 0 ]; then
    echo -e "${RED}${BOLD}[RUNTIME ERROR]${RESET} exit code: ${EXIT_CODE}"
    echo "$ACTUAL_OUTPUT"
    exit 1
fi

# --- output ---
if [ -n "$EXPECT_FILE" ]; then
    # compare mode: show diff
    EXPECTED_CONTENT=$(cat "$EXPECT_FILE")

    # write actual output to temp file for diff
    ACTUAL_TMP=$(mktemp)
    echo "$ACTUAL_OUTPUT" > "$ACTUAL_TMP"

    if diff "$ACTUAL_TMP" "$EXPECT_FILE" > /dev/null 2>&1; then
        echo -e "${GREEN}${BOLD}[ACCEPTED]${RESET} output matches expected (${ELAPSED}ms)"
    else
        echo -e "${RED}${BOLD}[WRONG ANSWER]${RESET} output differs from expected (${ELAPSED}ms)"
        echo ""
        echo -e "${BOLD}--- diff (expected vs actual) ---${RESET}"
        diff --color=always "$EXPECT_FILE" "$ACTUAL_TMP" || true
    fi

    rm -f "$ACTUAL_TMP"
else
    # no expected output: just print result
    echo -e "${GREEN}${BOLD}[DONE]${RESET} ${ELAPSED}ms"
    echo ""
    if [ -n "$ACTUAL_OUTPUT" ]; then
        echo "$ACTUAL_OUTPUT"
    fi
fi