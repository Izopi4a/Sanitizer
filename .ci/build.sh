#!/usr/bin/env bash

PROJECT_ROOT=$(readlink -enq "$(dirname $0)/../")

zephir generate --backend=ZendEngine3

cd ${PROJECT_ROOT}/ext
phpize
./configure --with-php-config=$(phpenv which php-config) --enable-sanitizer

make -j"$(getconf _NPROCESSORS_ONLN)"
make install

phpenv config-add ${PROJECT_ROOT}/.ci/sanitizer.ini

cd ${PROJECT_ROOT}

exit $?
