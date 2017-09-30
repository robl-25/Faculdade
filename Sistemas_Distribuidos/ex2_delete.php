<?php
require 'vendor/autoload.php';
date_default_timezone_set('America/New_York');

$sdk = new Aws\Sdk([
    'region'   => 'us-west-2',
    'version'  => 'latest'
]);

$dynamodb = $sdk->createDynamoDb();

$tableName = 'Caronas';

echo "Deleting the table $tableName...\n";

$result = $dynamodb->deleteTable([
    'TableName' => $tableName
]);

$dynamodb->waitUntil('TableNotExists', [
    'TableName' => $tableName,
    '@waiter' => [
        'delay'       => 5,
        'maxAttempts' => 20
    ]
]);

echo "The table $tableName has been deleted.\n";

?>
