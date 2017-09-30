<?php
    require 'vendor/autoload.php';
    require 'credentials.csv';

    $s3 = new Aws\S3\S3Client([
        'version' => 'latest',
        'region'  => 'us-west-2'
    ]);

    $sharedConfig = [
        'region'  => 'us-west-2',
        'version' => 'latest'
    ];

    $sdk = new Aws\Sdk($sharedConfig);

    $client = $sdk->createS3();

    $sdk = new Aws\Sdk([
        'region'   => 'us-west-2',
        'version'  => 'latest',
        'DynamoDb' => [
            'region' => 'us-west-2'
        ]
    ]);

    $client = $sdk->createDynamoDb();

    $s3Client = $sdk->createS3();

    /*$result = $s3Client->putObject([
        'Bucket' => 'my-bucket',
        'Key'    => 'my-key',
        'Body'   => 'this is the body!'
    ]);*/

    $result = $s3Client->getObject([
        'Nome' => 'Mariane',
        'Key'    => '2'
    ]);

    echo $result['Nome'];
?>
