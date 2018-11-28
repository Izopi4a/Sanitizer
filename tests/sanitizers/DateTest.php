<?php
    declare(strict_types=1);

    use Sanitizer\Sanitizers\Date;

    use PHPUnit\Framework\TestCase;

    final class DateTest extends TestCase {

        /**
         * @param $value
         *
         * @return Date
         */
        protected function getClass($value) {

            $b = new Date();
            $b->setRawValue($value);

            return $b;
        }

        public function testString() : void {

            $date = $this->getClass('asdasd');
            $date->setReadFormat("d-m-Y", true);

            $this->assertEquals("", $date->getValue());
        }

        public function testException() : void {

            $date = $this->getClass('asdasd');

            $this->expectException("\Exception");

            $date->getValue();
        }

        public function testWorking() : void {

            $date = $this->getClass('10-22-2018');
            $date->setReadFormat("m-d-Y", true);

            $this->assertEquals("10-22-2018", $date->getValue());
        }
    }
