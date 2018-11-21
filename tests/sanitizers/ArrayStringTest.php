<?php
    declare(strict_types=1);

    use Sanitizer\Sanitizers\ArrayString;

    use PHPUnit\Framework\TestCase;

    final class ArrayStringTest extends TestCase {

        /**
         * @param $value
         *
         * @return ArrayString
         */
        protected function getClass($value) {

            $a = new ArrayString();
            $a->setRawValue($value);

            return $a;
        }

        public function testNormal() : void {

            $input = ['a','b','c'];

            $array = $this->getClass(['a','b','c']);
            $this->assertEquals($array->getValue(), $input);
        }

        public function testMaxItems() : void {

            $array = $this->getClass(['a','b','c','d']);
            $array->setMaxItems(2);

            $this->assertEquals($array->getValue(), ['a','b']);
        }

        public function testManyMaxItems() : void {

            $input = ['a','b','c','d','e'];

            $array = $this->getClass($input);
            $array->setMaxItems(10);

            $this->assertEquals($array->getValue(), $input);
        }

        public function testNull() : void {

            $array = $this->getClass(null);

            $this->assertEquals($array->getValue(), []);
        }

        public function testString() : void {

            $array = $this->getClass('aaaabbb');

            $this->assertEquals($array->getValue(), []);
            unset($array);

            $array = $this->getClass('[a => 1]');

            $this->assertEquals($array->getValue(), []);
        }

        public function testBool() : void {

            $array = $this->getClass(false);

            $this->assertEquals($array->getValue(), []);
            unset($array);

            $array = $this->getClass(true);
            $this->assertEquals($array->getValue(), []);
        }

        public function testMaxValue() : void {

            $array = $this->getClass([
                'aaaaaaaaaaaaaaaaaaaaaaaaa',
                'bbb'
            ]);
            $array->setMaximum(10);
            $v = $array->getValue();

            $this->assertEquals(1, count($v));
            $this->assertEquals($v, ['bbb']);

        }

        public function testMinValue() : void {

            $array = $this->getClass([
                'aaaaaaaaaaaaaaaaaaaaaaaaa',
                'bbb'
            ]);
            $array->setMinimum(10);
            $v = $array->getValue();

            $this->assertEquals(1, count($v));
            $this->assertEquals(['aaaaaaaaaaaaaaaaaaaaaaaaa'], $v);

        }
    }