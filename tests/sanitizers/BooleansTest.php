<?php
    declare(strict_types=1);

    use Sanitizer\Sanitizers\Booleans;

    use PHPUnit\Framework\TestCase;

    final class BooleansTest extends TestCase {

        /**
         * @param $value
         *
         * @return Booleans
         */
        protected function getClass($value) {

            $b = new Booleans();
            $b->setRawValue($value);

            return $b;
        }

        public function testString() : void {

            $bool = $this->getClass('asdasd');

            $this->assertFalse($bool->getValue());

        }

        public function testOneString() : void {

            $bool = $this->getClass('1');

            $this->assertTrue($bool->getValue());

        }

        public function testZeroString() : void {

            $bool = $this->getClass('0');

            $this->assertFalse($bool->getValue());

        }

        public function testTwoString() : void {

            $bool = $this->getClass('2');

            $this->assertFalse($bool->getValue());
        }

        public function testOneInt() : void {

            $bool = $this->getClass(1);

            $this->assertTrue($bool->getValue());
        }

        public function testZeroInt() : void {

            $bool = $this->getClass(0);

            $this->assertFalse($bool->getValue());
        }

        public function testTwoInt() : void {

            $bool = $this->getClass(2);

            $this->assertFalse($bool->getValue());
        }

        public function testEmptyArray() : void {

            $bool = $this->getClass([]);

            $this->assertFalse($bool->getValue());
        }

        public function testArray() : void {

            $bool = $this->getClass(['a' => 1, 2 => 3]);

            $this->assertFalse($bool->getValue());
        }

        public function testNull() : void {

            $bool = $this->getClass(null);

            $this->assertFalse($bool->getValue());
        }
    }