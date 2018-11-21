<?php

    namespace Sanitizer\Sanitizers;

    use Sanitizer\SanitizerInterface;
    use Sanitizer\Sanitizer;

    class ArrayString extends Sanitizer implements SanitizerInterface {

        protected $minLength = null;
        protected $maxLength = null;
        /**
         * @var array
         */
        protected $val = [];

        /** @var int  */
        protected $maxItems = -1;

        /**
         * returns filtered value
         *
         * @return array
         */
        public function getValue() : array {

            $v = $this->getRawValue();

            if (false === is_array($v)) {
                return $this->getDefaultValue();
            }
            //we ignore the keys and make a new array with 0...n keys
            $v = array_values($v);
            $max = $this->maxItems > -1 ? $this->maxItems : count($v);

            for ($i = 0; $i < $max; $i++) {

                if (false === isset($v[$i])) {
                    break;
                }

                $value = $v[$i];

                $strings = new Strings();
                $strings->setRawValue($value);
                $strings->setNullAsDefault(true);

                if ($this->maxLength !== null) {
                    $strings->setMaxLength($this->maxLength);
                }
                if ($this->minLength !== null) {
                    $strings->setMinLength($this->minLength);
                }

                $newValue = $strings->getValue();

                if ($newValue !== null) {
                    $this->val[] = $newValue;
                }
            }

            return $this->val;
        }

        /**
         * set maximum number of elements inside the array
         *
         * THIS DOES NOT GUARANTEE THE ARRAY WILL HAVE {$amount} of ITEMS
         *
         * @param int $maxItems
         *
         * @return $this
         */
        public function setMaxItems(int $maxItems) {

            $this->maxItems = $maxItems;

            return $this;
        }

        /**
         * updates object to set required minimum
         *
         * @param int $min
         *
         * @return $this
         */
        public function setMinimum(int $min) {

            $this->minLength = $min;

            return $this;
        }

        /**
         * updates object to set required maximum
         *
         * @param int $max
         *
         * @return $this
         */
        public function setMaximum(int $max) {

            $this->maxLength = $max;

            return $this;
        }

        /**
         * returns default value for this object
         *
         * @return array
         */
        public function getDefaultValue() : array {

            return [];
        }
    }