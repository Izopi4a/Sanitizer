#!/usr/bin/env bash

ls -al `$(phpenv which php-config) --extension-dir`
echo

$(phpenv which php) -v
echo

$(phpenv which php-config) --vernum
echo

$(phpenv which php) -m
echo

PROJECT_ROOT=$(readlink -enq "$(dirname $0)/../")

if [ -f "${PROJECT_ROOT}/compile-errors.log" ]; then
	cat "${PROJECT_ROOT}/compile-errors.log"
fi

if [ -f "${PROJECT_ROOT}/compile-errors.log" ]; then
	cat "${PROJECT_ROOT}/compile-errors.log"
fi
