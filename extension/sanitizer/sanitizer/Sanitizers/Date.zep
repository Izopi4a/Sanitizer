namespace Sanitizer\Sanitizers;

use Sanitizer\Sanitizer;

class Date extends Sanitizer {

    /**
     * @var string
     */
    protected val = "";

    /**
     * @var string
     */
    protected readFormat = "";

    /**
     * @var string
     */
    protected returnFormat = "";

    /**
     * @var \DateTimeZone
     */
    protected timeZone = null;

    /**
     * @var bool
     */
    protected returnAsObject = false;

    /**
     * @var bool
     */
    protected returnAsTimestamp = false;

    /**
     * @var bool
     */
    protected manualTime = false;

    /**
     * @var int
     */
    protected hour = 0;

    /**
     * @var int
     */
    protected minute = 0;

    /**
     * @var int
     */
    protected second = 0;

    /**
     * returns formatted value
     *
     * @return \DateTime|int|string|null
     * @throws \Exception
     */
    public function getValue() {

        var strings;

        let strings = new Strings();
        strings->setRawValue(this->getRawValue());
        strings->setNullAsDefault(true);

        var v = strings->getValue();

        if (v === null) {
            return this->getDefaultValue();
        }

        let v = this->readDate(v);

        if (v === null) {
            return this->getDefaultValue();
        }

        //from this point date object contains valid date
        let this->val = v;

        if (this->returnAsObject === true) {
            return this->val;
        }

        if (this->returnAsTimestamp) {
            return this->val->getTimestamp();
        }

        return this->val->format(this->returnFormat);
    }

    /**
     * If Date is valid, timestamp will be returned
     *
     * @param bool state
     *
     * @return this
     */
    public function setReturnAsTimeStamp(bool state) {

        let this->returnAsTimestamp = state;

        return this;
    }

    /**
     * sets the time of returned object
     * useful when post contains from -to
     * than you can set from 00:00:01 to 23.:59:59
     *
     * @param int|null $hours
     * @param int|null $minutes
     * @param int|null $seconds
     *
     * @return $this
     */
    public function setTimeChange(int! hours = 0, int! minutes = 0, int! seconds = 0) {

        let this->hour = hours;
        let this->minute = minutes;
        let this->second = seconds;

        let this->manualTime = true;

        return this;
    }

    /**
     * when returning a value, if it is valid
     * \DateTime object will be returned instead of formatted string date
     *
     * @param bool state
     *
     * @return this
     */
    public function setReturnAsObject(bool state) {

        let this->returnAsObject = state;

        return this;
    }

    /**
     * @param string value
     *
     * @return \DateTime | null
     * @throws \Exception
     */
    protected function readDate(string! value) -> <\DateTime> | null {

        var date;

        if (this->readFormat === "") {
            throw new \Exception("Read format must be specified");
        }

        if (null !== this->timeZone) {

            let date = \DateTime::createFromFormat(this->readFormat, value, this->timeZone);
        } else {

            let date = \DateTime::createFromFormat(this->readFormat, value);
        }

        if (date && this->manualTime === true) {
            let date = date->setTime(this->hour, this->minute, this->second);
        }

        if (false === date) {
            return null;
        }

        return date;
    }

    /**
     * @param \DateTimeZone zone
     *
     * @return this
     */
    public function setTimeZone(<\DateTimeZone> zone) {

        let this->timeZone = zone;

        return this;
    }

    /**
     * @param string format
     * @param bool   setAsReturn
     *
     * @return this
     */
    public function setReadFormat(string! format, bool setAsReturn = false) {

        let this->readFormat = format;

        if (setAsReturn === true) {
            this->setReturnFormat(format, false);
        }

        return this;
    }

    /**
     * @param string format
     * @param bool   setAsRead
     *
     * @return this
     */
    public function setReturnFormat(string! format, bool setAsRead = false) {

        let this->returnFormat = format;

        if (setAsRead === true) {
            this->setReadFormat(format, false);
        }

        return this;
    }

    /**
     * returns default value for this object
     *
     * @return string|null
     */
    public function getDefaultValue() -> string | null {

        if (this->nullAsDefault) {
            return null;
        }

        return "";
    }
}
