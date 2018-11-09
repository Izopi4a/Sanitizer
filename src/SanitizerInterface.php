<?php

    namespace Sanitizer;

    interface SanitizerInterface {

        public function __construct(?string $variableName);

        public function getValue();

        public function getDefaultValue();

        public function getVariableName() : string ;

    }