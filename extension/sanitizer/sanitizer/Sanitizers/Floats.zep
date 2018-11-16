namespace Sanitizer\Sanitizers;

use Sanitizer\SanitizerInterface;
use Sanitizer\SizeInterface;
use Sanitizer\Sanitizer;

class Floats extends Sanitizer implements SanitizerInterface, SizeInterface {

    protected min = null;
    protected max = null;
    protected val = 0.00;
    protected maxDecimals = 2;

    /**
     * returns filtered value
     *
     * @return float|null
     */
    public function getValue() -> float | null {

        var v = this->getRawValue();

        if (is_string(v)) {
            let v = str_replace(",", '.', v);
        }

        if (false === is_numeric(v)) {
            return this->getDefaultValue();
        }

        let this->val = round(floatval(v), this->maxDecimals);

        if intval(this->val) === 0 {
            return this->getDefaultValue();
        }

        if (null !== this->min && false === this->checkMin()) {
            return this->getDefaultValue();
        }

        if (null !== this->max && false === this->checkMax()) {
            return this->getDefaultValue();
        }

        return this->val;
    }

    /**
     * @param int max
     *
     * @return this
     */
    public function setMaxDecimals(int max) {

        let this->maxDecimals = max;

        return this;
    }

    /**
     * validates if number is > than set minimum
     *
     * @return bool
     */
    protected function checkMin()-> bool {

        return this->val <= this->min;
    }

    /**
     * validates if value is < than set maximum
     *
     * @return bool
     */

    protected function checkMax() -> bool {

        return this->max >= this->val;
    }

    /**
     * updates object to set required minimum
     *
     * @param int min
     *
     * @return this
     */
    public function setMinimum(int min) {

        let this->min = min;

        return this;
    }

    /**
     * updates object to set required maximum
     *
     * @param int max
     *
     * @return this
     */
    public function setMaximum(int max) {

        let this->max = max;

        return this;
    }

    /**
     * returns default value for this object
     *
     * @return float|null
     */
    public function getDefaultValue() -> float | null {

        if (this->nullAsDefault) {
            return null;
        }

        return 0.00;
    }
}