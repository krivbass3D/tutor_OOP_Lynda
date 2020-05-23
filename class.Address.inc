<?php

/**
 * Physical address. 
 */
class Address {

  const ADDRESS_TYPE_RESIDENCE = 1;
  const ADDRESS_TYPE_BUSINESS = 2;
  const ADDRESS_TYPE_PARK = 3;

  static public $valid_address_types = array(
     Address::ADDRESS_TYPE_RESIDENCE => 'Адр_Проживания',
      Address::ADDRESS_TYPE_BUSINESS => 'Адр_Рабочий',
      Address::ADDRESS_TYPE_PARK => 'Адр_отдыха',

  );
  // Street address.
  public $street_address_1;
  public $street_address_2;
  
  // Name of the City.
  public $city_name;
  
  // Name of the subdivison.
  public $subdivision_name;
  
  // Postal code.
  protected $_postal_code;
  
  // Name of the Country.
  public $country_name;
  
  // Primary key of an Address.
  protected $_address_id;
  
  // When the record was created and last updated.
  protected $_time_created;
  protected $_time_updated;


  function __construct($data = array())
  {
       $this->_time_created=time();
       if (!is_array($data))
       {
           trigger_error('НЕ удалось создать адресс с помощью ' . get_class($name));
       }
       //Если есть хоть одно значение заполняем адресс
      if (count($data) > 0)
      {
          foreach ($data as $name => $value)
          {
              //Специальный случай для защищенных свойств
              if (in_array($name, array(
                  'time_created',
                  'time_updated',
              )))
              {
                  $name = "_" . $name;
              }
              $this->$name = $value;
          }
      }
  }


    /**
   * Magic __get.
   * @param string $name 
   * @return mixed
   */
  function __get($name) {
    // Postal code lookup if unset.
    if (!$this->_postal_code) {
      $this->_postal_code = $this->_postal_code_guess();
    }
    
    // Attempt to return a protected property by name.
    $protected_property_name = '_' . $name;
    if (property_exists($this, $protected_property_name)) {
      return $this->$protected_property_name;
    }
    
    // Unable to access property; trigger error.
    trigger_error('Undefined property via __get: ' . $name);
    return NULL;
  }
  
  /**
   * Magic __set.
   * @param string $name
   * @param mixed $value 
   */
  function __set($name, $value) {
    // Allow anything to set the postal code.
    if ('postal_code' == $name) {
      $this->$name = $value;
      return;
    }
    
    // Unable to access property; trigger error.
    trigger_error('Undefined or unallowed property via __set(): ' . $name);
  }

  function  __toString()
  {
      // TODO: Implement __toString() method.
      return $this->display();
  }


    /**
   * Guess the postal code given the subdivision and city name.
   * @todo Replace with a database lookup.
   * @return string 
   */
  protected function _postal_code_guess() {
    return 'LOOKUP';
  }
  
  /**
   * Display an address in HTML.
   * @return string 
   */
  function display() {
    $output = '';
    
    // Street address.
    $output .= $this->street_address_1;
    if ($this->street_address_2) {
      $output .= '<br/>' . $this->street_address_2;
    }
    
    // City, Subdivision Postal.
    $output .= '<br/>';
    $output .= $this->city_name . ', ' . $this->subdivision_name;
    $output .= ' ' . $this->postal_code;
    
    // Country.
    $output .= '<br/>';
    $output .= $this->country_name;
    
    return $output;
  }
  //Ghjdthztn flhtccf
  static public function isValidAddressTypeId ($address_type_id)
  {

  }
}
