namespace Sanitizer\Sanitizers;

use Sanitizer\SanitizerInterface;
use Sanitizer\Sanitizer;

class ArrayString extends Sanitizer implements SanitizerInterface {

    protected minLength = null;
    protected maxLength = null;
    /**
     * @var array
     */
    protected val = [];

    /** @var int  */
    protected maxItems = -1;

    /**
     * returns filtered value
     *
     * @return array
     */
    public function getValue() -> array {

        var v = this->getRawValue(),
            strings;

        int i, max;

        if typeof v != "array" {
            return this->getDefaultValue();
        }

        //we ignore the keys and make a new array with 0...n keys
        let v = array_values(v);
        let max = this->maxItems > -1 ? this->maxItems : count(v);

        for i in range(0, max - 1) {

            if (false === isset(v[i])) {
                break;
            }

            var value = v[i];

            let strings = new Strings();
            strings->setRawValue(value);
            strings->setNullAsDefault(true);

            if (this->maxLength !== null) {
                strings->setMaxLength(this->maxLength);
            }
            if (this->minLength !== null) {
                strings->setMinLength(this->minLength);
            }

            var newValue = strings->getValue();

            if (newValue !== null) {
                let this->val[] = newValue;
            }
        }


        return this->val;
    }

    /**
     * set maximum number of elements inside the array
     *
     * THIS DOES NOT GUARANTEE THE ARRAY WILL HAVE {amount} of ITEMS
     *
     * @param int maxItems
     *
     * @return this
     */
    public function setMaxItems(int! maxItems) {

        let this->maxItems = maxItems;

        return this;
    }

    /**
     * updates object to set required minimum
     *
     * @param int min
     *
     * @return this
     */
    public function setMinimum(int! min) {

        let this->minLength = min;

        return this;
    }

    /**
     * updates object to set required maximum
     *
     * @param int max
     *
     * @return this
     */
    public function setMaximum(int! max) {

        let this->maxLength = max;

        return this;
    }

    /**
     * returns default value for this object
     *
     * @return array|null
     */
    public function getDefaultValue() -> array {

        return [];
    }
}