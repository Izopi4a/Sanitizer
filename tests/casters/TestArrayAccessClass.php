<?php

    class TestArrayAccessClass implements ArrayAccess {

        private $container = [];

        public function __construct() {

            $this->container = [
                "a" => 1,
                "b" => 2222,
                "c" => "asdasdsadddddddd",
                "d" => "as",
                "e" => true,
                "f" => false,
            ];
        }

        public function offsetSet($offset, $value) {

            if (is_null($offset)) {
                $this->container[] = $value;
            } else {
                $this->container[$offset] = $value;
            }
        }

        public function offsetExists($offset) {

            return isset($this->container[$offset]);
        }

        public function offsetUnset($offset) {

            unset($this->container[$offset]);
        }

        public function offsetGet($offset) {

            return isset($this->container[$offset]) ? $this->container[$offset] : null;
        }
    }