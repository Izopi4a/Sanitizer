namespace Sanitizer\Sanitizers;

use Sanitizer\SanitizerInterface;
use Sanitizer\Sanitizer;

class Booleans extends Sanitizer implements SanitizerInterface {

    protected val = false;

    /**
     * returns filtered value
     *
     * @return bool
     */
    public function getValue() -> bool {

        var v = this->getRawValue();

        if (is_bool(v)) {
            return v;
        }

        if (true === is_numeric(v)) {

            let v = intval(v);

            if (v === 1) {

                return true;
            } elseif (v === 0) {

                return false;
            }

            return this->getDefaultValue();
        }

        if (is_string(v)) {

            var b = filter_var(v, FILTER_VALIDATE_BOOLEAN, FILTER_NULL_ON_FAILURE);

            if (b === null) {
                return this->getDefaultValue();
            }

            let this->val = b;
        }


        return this->val;
    }

    /**
     * returns default value for this object
     *
     * @return bool
     */
    public function getDefaultValue() -> bool {

        return false;
    }
}