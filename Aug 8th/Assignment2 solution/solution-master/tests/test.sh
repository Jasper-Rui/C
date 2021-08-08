#!/bin/sh

echo ======================================================
echo ====================== TEST $1 ========================
echo ======================================================
if timeout 10 ./miner/miner < tests/test.$1.in > tests/test.$1.out; then 
  if diff tests/test.$1.out tests/test.$1.expected > /dev/null; then
    echo PASSED
  else
    echo FAILED
    echo ======
    echo Expected Output:
    echo ++++++++++++++++
    cat tests/test.$1.expected
    echo =====================
    echo Actual Output:
    echo ++++++++++++++++
    cat tests/test.$1.out
    exit 1
  fi
elif [ $? == 124 ]; then
  echo TIMEOUT
  exit 1
else 
  echo Abnormal program termination: the program crashed
  echo Exit code $?
  exit 1
fi
