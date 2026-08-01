#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

clear

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}      LOCAL ONLINE JUDGE v1.0${NC}"
echo -e "${BLUE}========================================${NC}"
echo

echo -e "${YELLOW}Compiling...${NC}"

g++-15 -std=c++20 \
-Wall \
-Wextra \
-Wshadow \
-O2 \
Solution.cpp -o Solution

if [ $? -ne 0 ]; then
    echo
    echo -e "${RED}Compilation Failed${NC}"
    exit 1
fi

echo -e "${GREEN}Compilation Successful${NC}"
echo

echo -e "${YELLOW}Running Tests...${NC}"
echo

/usr/bin/time ./Solution

echo
echo -e "${GREEN}Finished.${NC}"

rm -f Solution