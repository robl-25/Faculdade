<?php
require 'vendor/autoload.php';

date_default_timezone_set('UTC');

use Aws\DynamoDb\Exception\DynamoDbException;

$sdk = new Aws\Sdk([
    'region'   => 'us-west-2',
    'version'  => 'latest'
]);

$dynamodb = $sdk->createDynamoDb();

$tableName = 'Usuario';
/*
echo "# Creating table $tableName...\n";

try {
    $response = $dynamodb->createTable([
        'TableName' => $tableName,
        'AttributeDefinitions' => [
            [
                'AttributeName' => 'Id',
                'AttributeType' => 'N'
            ]
        ],
        'KeySchema' => [
            [
                'AttributeName' => 'Id',
                'KeyType' => 'HASH'  //Partition key
            ]
        ],
        'ProvisionedThroughput' => [
            'ReadCapacityUnits'    => 5,
            'WriteCapacityUnits' => 6
        ]
    ]);

    $dynamodb->waitUntil('TableExists', [
        'TableName' => $tableName,
        '@waiter' => [
            'delay'       => 5,
            'maxAttempts' => 20
        ]
    ]);

    print_r($response->getPath('TableDescription'));

    echo "table $tableName has been created.\n";
} catch (DynamoDbException $e) {
    echo $e->getMessage() . "\n";
    exit ("Unable to create table $tableName\n");
}

####################################################################
# Updating the table
/*
echo "# Updating the provisioned throughput of table $tableName.\n";
try {

$response = $dynamodb->updateTable([
    'TableName' => $tableName,
    'ProvisionedThroughput'    => [
        'ReadCapacityUnits'    => 6,
        'WriteCapacityUnits' => 7
    ]
]);

$dynamodb->waitUntil('TableExists', [
    'TableName' => $tableName,
    '@waiter' => [
        'delay'       => 5,
        'maxAttempts' => 20
    ]
]);

echo "New provisioned throughput settings:\n";

$response = $dynamodb->describeTable(['TableName' => $tableName]);

echo "Read capacity units: " .
    $response['Table']['ProvisionedThroughput']['ReadCapacityUnits']."\n";
echo "Write capacity units: " .
    $response['Table']['ProvisionedThroughput']['WriteCapacityUnits']."\n";

} catch (DynamoDbException $e) {
    echo $e->getMessage() . "\n";
    exit ("Unable to update table $tableName\n");
}

####################################################################
# Deleting the table

/*try {
    echo "# Deleting table $tableName...\n";

    $response = $dynamodb->deleteTable([ 'TableName' => $tableName]);

    $dynamodb->waitUntil('TableNotExists', [
        'TableName' => $tableName,
        '@waiter' => [
            'delay'       => 5,
            'maxAttempts' => 20
        ]
    ]);
    echo "The table has been deleted.\n";

} catch (DynamoDbException $e) {
    echo $e->getMessage() . "\n";
    exit ("Unable to delete table $tableName\n");
}*/

####################################################################
# List all table names for this AWS account, in this region
/*
echo "# Listing all of your tables in the current region...\n";

$tables = [];

// Walk through table names, two at a time

unset($response);

do {
    if (isset($response)) {
        $params = [
            'Limit' => 2,
            'ExclusiveStartTableName' => $response['LastEvaluatedTableName']
        ];
    }else {
        $params = ['Limit' => 2];
    }

    $response = $dynamodb->listTables($params);

    foreach ($response['TableNames'] as $key => $value) {
        echo "$value\n";
    }

    $tables = array_merge($tables, $response['TableNames']);

} while ($response['LastEvaluatedTableName']);

// Print total number of tables

echo "Total number of tables: ";
print_r(count($tables));
echo "\n";*/

#######################################################################
# Update a one item

$response = $dynamodb->putItem([
    'TableName' => $tableName,
    'Item' => [
        'Id'       => ['N'      => '2'      ], // Primary Key
        'Nome'    => ['S'      => 'Bruna de Jesus' ],
        'Idade'     => ['N'      => '25' ],
        'Nome_usuario' => ['S' => 'bruna25'],
        'Senha' => ['S' => 'h9ouer43958y'] //salva com criptografia
     ],
    'Item' => [
        'Id'       => ['N'      => '1'      ], // Primary Key
        'Nome'    => ['S'      => 'Ricardo' ],
        'Idade'     => ['S'      => '23' ],
        'Nome_usuario' => ['S' => 'ricardo23'],
        'Senha' => ['S' => 'atsdf78defas8'] ]
                
]);

print_r($response);

#########################################################################
# Update a more items
/*$tableNameOne = 'Caronas';

$response = $dynamodb->batchWriteItem([
    'RequestItems' => [
        $tableNameOne => [
            [
                'PutRequest' => [
                    'Item' => [
                        'Id'       => ['N'      => '3'      ], // Primary Key
                        'Date'    => ['S'      => '30-04-2016' ],
                        'Time'     => ['S'      => '10:34' ],
                        'User'    => ['S'      => 'Usuario1' ],
                        'Car'  => ['SS'  => ['Vectra', 'Red', 'DEV666'] ]
                    ],
                    'Item' => [
                        'Id'       => ['N'      => '4'      ], // Primary Key
                        'Date'    => ['S'      => '08-05-2016' ],
                        'Time'     => ['S'      => '09:56' ],
                        'User'    => ['S'      => 'Usuario4' ],
                        'Car'  => ['SS'  => ['Vectra', 'Green', 'AHS698'] ]
                    ]
                ]
            ]
        ]
        /*$tableNameOne => [
            [
                'PutRequest' => [

                ]
            ]
        ]*/
/*    ]
]);*/

?>
