#!/usr/bin/env bash

set -e

pushd /tmp

# |--------------------------------------------------------------------------
# | zephir parser
# |--------------------------------------------------------------------------
# |
# | installs latest zephir parser extension
# |

set -e

ZEPHIR_PARSER_VERSION=${ZEPHIR_PARSER_VERSION:-development}

git clone --depth=1 -v https://github.com/phalcon/php-zephir-parser.git -b ${ZEPHIR_PARSER_VERSION} /tmp/parser/
cd /tmp/parser
phpize
./configure
make
make install

echo "extension=zephir_parser.so" >> $(phpenv root)/versions/$(phpenv version-name)/etc/conf.d/zephir-parser.ini

php --ri 'Zephir Parser'

# |--------------------------------------------------------------------------
# | zephir
# |--------------------------------------------------------------------------
# |
# | installs latest zephir extension
# | DO NOT DELETE THE DIRECTORY
# |

#mkdir -p /usr/share/zephir
#git clone --depth=1 -v https://github.com/phalcon/zephir /tmp/zephir
#cd /tmp/zephir
#./install -c && composer install --ignore-platform-reqs