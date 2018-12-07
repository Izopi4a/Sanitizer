<?php

    namespace Sanitizer;

    abstract class Sanitizer implements SanitizerInterface {

        /** @var bool */
        protected $nullAsDefault = false;

        protected $rawValue;

        /** @var string  */
        protected $variableName = "";

        /**
         * Sanitizer constructor.
         *
         * @param null|string $variableName
         */
        public function __construct(?string $variableName = null) {

            if ($variableName === null) {
                return;
            }
            $this->variableName = $variableName;
        }

        /**
         * variable name / key name in data array
         *
         * @return string
         */
        public function getVariableName() : string {

            return $this->variableName;
        }

        /**
         * when defaultValue is returned if enabled
         *
         * @param bool $state
         *
         * @return $this
         */
        public function setNullAsDefault(bool $state) {

            $this->nullAsDefault = $state;

            return $this;
        }

        /**
         * assigns value to be sanitized to the object
         *
         * @param $value
         */
        public function setRawValue($value) {

            $this->rawValue = $value;
        }

        /**
         * returns non-serialized value of the object
         *
         * @return mixed
         */
        public function getRawValue() {

            return $this->rawValue;
        }
    }
