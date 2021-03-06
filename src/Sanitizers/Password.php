<?php

    namespace Sanitizer\Sanitizers;

    use Sanitizer\LengthInterface;
    use Sanitizer\Sanitizer;

    class Password extends Sanitizer implements LengthInterface {

        protected $minLength = null;
        protected $maxLength = null;
        protected $val = "";

        /**
         * returns filtered value
         *
         * @return null|string
         */
        public function getValue() : ?string {

            $v = $this->getRawValue();

            if (null === $v || is_bool($v) || is_array($v)) {
                return $this->getDefaultValue();
            }

            $this->val = $v;

            if ($this->val === "" || trim($this->val) === "") {
                return $this->getDefaultValue();
            }

            if (null !== $this->minLength && false === $this->checkMinLength()) {
                return $this->getDefaultValue();
            }

            if (null !== $this->maxLength && false === $this->checkMaxLength()) {
                return $this->getDefaultValue();
            }

            return $this->val;
        }

        /**
         * validates if string length is more than the one set
         *
         * @return bool
         */

        protected function checkMinLength() : bool {

            return $this->minLength <= strlen($this->val);
        }

        /**
         * validates if string length is less than the one set
         *
         * @return bool
         */
        protected function checkMaxLength() : bool {

            return $this->maxLength >= strlen($this->val);
        }

        /**
         * updates object property for min length
         *
         * @param int $min
         *
         * @return $this
         */
        public function setMinLength(int $min) {

            $this->minLength = $min;

            return $this;
        }

        /**
         * updates object property for max length
         *
         * @param int $max
         *
         * @return $this
         */
        public function setMaxLength(int $max) {

            $this->maxLength = $max;

            return $this;
        }

        /**
         * returns default value for this object
         *
         * @return null|string
         */
        public function getDefaultValue() : ?string {

            if ($this->nullAsDefault) {
                return null;
            }

            return "";
        }
    }
