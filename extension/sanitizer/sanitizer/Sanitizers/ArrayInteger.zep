namespace Sanitizer\Sanitizers;

use Sanitizer\Sanitizer;

class ArrayInteger extends Sanitizer {

    protected min = null;
    protected max = null;
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
            integers;

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

            let integers = new Integer();
            integers->setRawValue(value);
            integers->setNullAsDefault(true);

            if (this->max !== null) {
                integers->setMaximum(this->max);
            }
            if (this->min !== null) {
                integers->setMinimum(this->min);
            }

            var newValues = integers->getValue();

            if (newValues !== null) {
                let this->val[] = newValues;
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
    public function setMaximum(int! max) {

        let this->max = max;

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
