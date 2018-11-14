ROOT_DIR = $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

SHELL ?= /bin/bash
PHP ?= /usr/bin/php
INI_FILE ?= /etc/php/7.2/cli/php.ini
ARGS = $(filter-out $@,$(MAKECMDGOALS))

APP_NAME = Sanitizer

.SILENT: ;               # no need for @
.ONESHELL: ;             # recipes execute in same shell
.NOTPARALLEL: ;          # wait for this target to finish
.EXPORT_ALL_VARIABLES: ; # send all vars to shell
Makefile: ;              # skip prerequisite discovery

# Run make help by default
.DEFAULT_GOAL = help

ifneq ("$(wildcard ./VERSION)","")
VERSION ?= $(shell cat ./VERSION | head -n 1)
else
VERSION ?= 0.0.1
endif

.PHONY: .title
.title:
	printf "\n                \033[95m%s: v%s\033[0m\n" "$(APP_NAME)" $(VERSION)

# Public targets

.PHONY: test
test: ## Executes tests
		$(PHP) ./vendor/bin/phpunit

.PHONY: test-extension
test-extension: ## Executes tests for extension by first moving src dir
		sudo sed -i -e 's/;extension=sanitizer.so/extension=sanitizer.so/g' $(INI_FILE)
		mv src src_
		$(PHP) ./vendor/bin/phpunit
		mv src_ src
		sudo sed -i -e 's/extension=sanitizer.so/;extension=sanitizer.so/g' $(INI_FILE)

.PHONY: vendor-install
vendor-install: ## Install PHP dependencies
		$(PHP) composer.phar install

.PHONY: help
help: .title ## Show this help and exit (default target)
	echo ''
	printf "                %s: \033[94m%s\033[0m \033[90m[%s] [%s]\033[0m\n" "Usage" "make" "target" "ENV_VARIABLE=ENV_VALUE ..."
	echo ''
	echo '                Available targets:'
	# Print all commands, which have '##' comments right of it's name.
	# Commands gives from all Makefiles included in project.
	# Sorted in alphabetical order.
	echo '                ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━'
	grep -hE '^[a-zA-Z. 0-9_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | \
		 awk 'BEGIN {FS = ":.*?## " }; {printf "\033[36m%+15s\033[0m: %s\n", $$1, $$2}'
	echo '                ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━'
	echo ''

%:
	@:
