<?php
/**
 * Custom WordPress configurations on "wp-config.php" file.
 *
 * This file has the following configurations: MySQL settings, Table Prefix, Secret Keys, WordPress Language, ABSPATH and more.
 * For more information visit {@link https://codex.wordpress.org/Editing_wp-config.php Editing wp-config.php} Codex page.
 * Created using {@link http://generatewp.com/wp-config/ wp-config.php File Generator} on GenerateWP.com.
 *
 * @package WordPress
 * @generator GenerateWP.com
 */


/* MySQL settings */
define('DB_NAME', getenv('MYSQL_DATABASE'));
define('DB_USER', getenv('MYSQL_USER'));
define('DB_PASSWORD', getenv('MYSQL_PASSWORD'));
define('DB_HOST', 'mariadb');
define('DB_CHARSET', 'utf8' );
define('DB_COLLATE', '' );


/* MySQL database table prefix. */
$table_prefix = 'wp_';


/* Authentication Unique Keys and Salts. */
/* https://api.wordpress.org/secret-key/1.1/salt/ */
define('AUTH_KEY',         '+i86oL0mpR4+xvmUY_zQ3efo1`.sT*|%7{EHvm=L(_+Ny:ulo/R#oa4WX|s!hbHK');
define('SECURE_AUTH_KEY',  '944!9dGqrI2QMXcUp4wmO/yw?8=Yfd?eraS}}l]M_.7mz=dyMRLv|[k1osVESpit');
define('LOGGED_IN_KEY',    '.,s0ZH3*d]|6#MRkU*3kA @7lE~gYYm3(4W73M;4PFB^lO?#23_{?(oF?k}_9xoO');
define('NONCE_KEY',        'RSj-,hoT4g&-{|qOCAg:# es?PP.B?{%5XVxmykIgz&c~W5kqkPXJJH`[9_f,y4R');
define('AUTH_SALT',        '~DM0!Vw;P)mK5L(,r1c&AyCj<&]+C*R=a*-l4sGn?|Y7_O/YRjJ-xTxND8lS0fj;');
define('SECURE_AUTH_SALT', 'IY^oOQ]sH%FJQ`6Ih7[D 0qA@ykSz9 yJ[z?#4#,&=@g*M<6I~ZTg>Z)*j/`$:rf');
define('LOGGED_IN_SALT',   '>jPl.f0rL71VNjVe5V7+PR6ga-t~||+2xyAuHg]-bjPh_wAP3qzO_{8gvHoXv1P4');
define('NONCE_SALT',       '({&.j;-|`g{;yF4mv7an(T$Hiu}!<Y#)to( 9 5_W t:$+pKRtOo1U )d+uZ;uL9');


/* Absolute path to the WordPress directory. */
if ( !defined('ABSPATH') )
	define('ABSPATH', dirname(__FILE__) . '/');

/* Sets up WordPress vars and included files. */
require_once(ABSPATH . 'wp-settings.php');