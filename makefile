# Helper file to remove the need to remember garbage commands
#

php := /usr/bin/php

.PHONY: test
test: ## Executes tests
		$(php) ./vendor/bin/phpunit

.PHONY: vendor-install
vendor-install: ## isntall deps
		$(php) composer.phar install

.PHONY: help
help: ## Display this help message
	@cat $(MAKEFILE_LIST) | grep -e "^[a-zA-Z_\-]*: *.*## *" | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'