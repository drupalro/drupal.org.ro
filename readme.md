#Asociația Drupal România#
[![Gitter](https://badges.gitter.im/Join Chat.svg)](https://gitter.im/drupalro/drupal.org.ro?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

Specifications: [Brief Specs for drupal.org.ro](https://github.com/drupalro/drupal.org.ro/wiki/Brief-Specs-for-drupal.org.ro)

Set-up instructions:

* Create the MySQL database and import data/drupalro.sql

```
mysql> create database drupalro;
$> cat data/drupalro.sql | mysql -u root -p drupalro
```

* Touch `sites/default/settings.php` and add a simple config file

```php

<?php

$databases = array (
  'default' =>
  array (
    'default' =>
    array (
      'database' => 'drupalro',
      'username' => 'root',
      'password' => 'root',
      'host' => 'db',
      'port' => '3306',
      'driver' => 'mysql',
      'prefix' => '',
    ),
  ),
);

$update_free_access = FALSE;
$drupal_hash_salt = 'todo_in_production_we_would_use_here_a_real_salt';
ini_set('session.gc_probability', 1);
ini_set('session.gc_divisor', 100);
ini_set('session.gc_maxlifetime', 200000);
ini_set('session.cookie_lifetime', 2000000);
# $cookie_domain = '.example.com';
$conf['404_fast_paths_exclude'] = '/\/(?:styles)\//';
$conf['404_fast_paths'] = '/\.(?:txt|png|gif|jpe?g|css|js|ico|swf|flv|cgi|bat|pl|dll|exe|asp)$/i';
$conf['404_fast_html'] = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN" "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd"><html xmlns="http://www.w3.org/1999/xhtml"><head><title>404 Not Found</title></head><body><h1>Not Found</h1><p>The requested URL "@path" was not found on this server.</p></body></html>';
```

* Copy conf/apache.template.conf to conf/apache.conf, customize it and link it from apache home

  ```sudo ln -s /home/user/work/drupalro/project/conf/apache.conf /etc/httpd/conf.d/drupalro.conf```

  and reload apache to create the new VH `sudo service httpd reload`

* Change admin password: drush user-password --password=secret admin & login with it.

* Brew a coffee! :-)
