<?php

    namespace Sanitizer;

    /**
     * class that helps you sanitize your user inputs
     *
     * Class Caster
     * @package Sanitizer
     */

    class IteratorCaster implements CasterInterface {

        protected $sanitizers = [];
        protected $data = [];

        public function __construct(\Iterator $data, ?array $items = null) {

            $this->data = $data;

            if ($items !== null) {
                foreach ($items AS $item) {
                    $this->add($item);
                }
            }
        }

        /**
         * adds sanitizer to the object
         * sanitizers are the one returning values from data source
         *
         * @param SanitizerInterface $sanitizer
         *
         * @return $this
         */

        public function add(SanitizerInterface $sanitizer) {

            $this->sanitizers[] = $sanitizer;

            return $this;
        }

        /**
         * returns sanitized data
         *
         * @return array
         */
        public function getData(): array {

            $data = [];

            /** @var \Sanitizer\SanitizerInterface $sanitizer */
            foreach ($this->sanitizers AS $sanitizer) {

                $varName = $sanitizer->getVariableName();

                if (isset($this->data[$varName]) === false) {

                    $data[$varName] = $sanitizer->getDefaultValue();
                    continue;
                }

                $sanitizer->setRawValue($this->data[$varName]);
                $data[$varName] = $sanitizer->getValue();
            }

            return $data;
        }
    }
