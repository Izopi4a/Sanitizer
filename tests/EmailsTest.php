<?php
    declare(strict_types=1);

    use Sanitizer\Sanitizers\Emails;

    use PHPUnit\Framework\TestCase;

    final class EmailsTest extends TestCase {

        /**
         * @param $value
         *
         * @return Emails
         */
        protected function getClass($value) {

            $e = new Emails(null);
            $e->setRawValue($value);

            return $e;
        }

        public function testEmptyString() : void {

            $emails = $this->getClass('asdasd');

            $this->assertEquals($emails->getValue(), "");
        }

        public function testValid() : void {

            $emails = $this->getClass('asdasd@axsajdas.com');

            $this->assertEquals($emails->getValue(), "asdasd@axsajdas.com");
        }

        public function testNull() : void {

            $emails = $this->getClass(null);

            $this->assertEquals($emails->getValue(), "");
        }

        public function testNullAsDefault() : void {

            $emails = $this->getClass(null);
            $emails->setNullAsDefault(true);

            $this->assertNull($emails->getValue());
        }

        public function testEscapeString() : void {

            $emails = $this->getClass('a\\ds""""asdsa@ddsfsdjfsd.com');
            $emails->setNullAsDefault(true);

            $this->assertEquals($emails->getValue(), 'adsasdsa@ddsfsdjfsd.com');
        }
    }