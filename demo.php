<?php

require 'class.Address.inc';

echo '<h2>Создание экземпляра Address</h2>';
$address = new Address;

echo '<h2>Пустой абресс</h2>';
echo '<tt><pre>' . var_export($address, TRUE) . '</pre></tt>';

echo '<h2>Setting properties / задание свойств...</h2>';
$address->street_address_1 = '555 Fake Street';
$address->city_name = 'Townsville';
$address->subdivision_name = 'State';
$address->postal_code = '12345';
$address->country_name = 'United States of America';
echo '<tt><pre>' . var_export($address, TRUE) . '</pre></tt>';

echo '<h2>Displaying address / Отображение адресса ...</h2>';
echo $address->display();

echo '<h2>Тестирование магических методов гет и сет ...</h2>';
unset ($address->postal_code);
echo $address->display();

echo '<h2>Тестирование создание адресса с помощью массива</h2>';
;$address2 = new Address(array(
    'street_address_1' => '123 Svato Mukolaj',
    'city_name' => 'Krivoy Rog',
    'subdivision_name' => 'REGION',
    'postal_code' => '66666',
    'country_name' => 'UA',
));
echo $address2->display();
echo '<h2>Address __toString</h2>';
echo $address2;

echo '<h2>Показ типов адрессов ...</h2>';
echo '<tt><pre>'.var_export(Address::$valid_address_types,TRUE).'</tt></pre>';

echo '<h2>Тестирование проверки ...</h2>';
/**
 * Display an address in HTML.
 * @return string
 */


}