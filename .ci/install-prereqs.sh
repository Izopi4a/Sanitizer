#!/usr/bin/env bash
#
# This file is part of the Phalcon.
#
# (c) Phalcon Team <team@phalconphp.com>
#
# For the full copyright and license information,
# please view the: https://github.com/phalcon/cphalcon/blob/master/LICENSE.txt

PROJECT_ROOT=$(readlink -enq "$(dirname $0)/../")

source ${PROJECT_ROOT}/.ci/ci-tools.sh

install_ext_from_src "zephir_parser" "https://github.com/phalcon/php-zephir-parser" ""
