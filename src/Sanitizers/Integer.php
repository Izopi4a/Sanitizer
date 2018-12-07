<?php

    namespace Sanitizer\Sanitizers;

    use Sanitizer\SizeInterface;
    use Sanitizer\Sanitizer;

    class Integer extends Sanitizer implements SizeInterface {

        protected $min = null;
        protected $max = null;
        protected $val = 0;

        /**
         * returns filtered value
         *
         * @return int|null
         */
        public function getValue() : ?int {

            $v = $this->getRawValue();

            if (false === is_numeric($v)) {
                return $this->getDefaultValue();
            }

            $this->val = intval($v);

            if ($this->val === 0) {
                return $this->getDefaultValue();
            }

            if (null !== $this->min && false === $this->checkMin()) {
                return $this->getDefaultValue();
            }

            if (null !== $this->max && false === $this->checkMax()) {
                return $this->getDefaultValue();
            }

            return $this->val;
        }

        /**
         * validates if number is > than set minimum
         *
         * @return bool
         */
        protected function checkMin() : bool {

            return $this->min <= $this->val;
        }

        /**
         * validates if value is < than set maximum
         *
         * @return bool
         */

        protected function checkMax() : bool {

            return $this->max >= $this->val;
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
         * @return int|null
         */
        public function getDefaultValue() : ?int {

            if ($this->nullAsDefault) {
                return null;
            }

            return 0;
        }
    }
