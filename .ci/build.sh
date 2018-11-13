#!/usr/bin/env bash

# trace ERR through pipes
set -o pipefail

# trace ERR through 'time command' and other functions
set -o errtrace

# set -u : exit the script if you try to use an uninitialised variable
set -o nounset

# set -e : exit the script if any statement returns a non-true return value
set -o errexit

PROJECT_ROOT=$(readlink -enq "$(dirname $0)/../")

cd ${PROJECT_ROOT}/extension/sanitizer
zephir generate --backend=ZendEngine3

cd ${PROJECT_ROOT}/extension/sanitizer/ext
phpize
./configure --with-php-config=$(phpenv which php-config) --enable-sanitizer

make -j"$(getconf _NPROCESSORS_ONLN)" > /dev/null 2> ../../../compile-errors.log
make install

phpenv config-add ${PROJECT_ROOT}/.ci/sanitizer.ini

cd ${PROJECT_ROOT}

exit $?
