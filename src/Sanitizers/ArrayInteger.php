<?php

    namespace Sanitizer\Sanitizers;

    use Sanitizer\SanitizerInterface;
    use Sanitizer\Sanitizer;

    class ArrayInteger extends Sanitizer implements SanitizerInterface {

        protected $min = null;
        protected $max = null;
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

                $integers = new Integer(null);
                $integers->setRawValue($value);
                $integers->setNullAsDefault(true);

                if ($this->max !== null) {
                    $integers->setMaximum($this->max);
                }
                if ($this->min !== null) {
                    $integers->setMaximum($this->min);
                }

                $newValues = $integers->getValue();

                if ($newValues !== null) {
                    $this->val[] = $newValues;
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

            $this->min = $min;

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

            $this->max = $max;

            return $this;
        }

        /**
         * returns default value for this object
         *
         * @return array|null
         */
        public function getDefaultValue() : array {

            return [];
        }
    }