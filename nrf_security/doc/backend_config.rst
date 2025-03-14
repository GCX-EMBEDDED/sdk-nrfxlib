.. _nrf_security_backend_config:
.. _nrf_security_legacy_config:

Legacy configurations and supported features
############################################

.. contents::
   :local:
   :depth: 2

This section covers the configurations available when using :ref:`legacy_crypto_support`.

.. _nrf_security_backend_config_multiple:

Configuring backends
********************

The legacy configuration does not allow multiple backends being enabled at the same time. 

The choice of implementation is controlled by setting :kconfig:`CONFIG_CC3XX_BACKEND` for devices with the CryptoCell hardware peripheral, or :Kconfig:`CONFIG_OBERON_BACKEND`.

.. _nrf_security_backends_cc3xx:

cc3xx backend
=============

Setting the Kconfig option :kconfig:`CONFIG_CC3XX_BACKEND` enables legacy crypto support for hardware accelerated cryptography using :ref:`nrf_cc3xx_mbedcrypto_readme`

.. _nrf_security_backends_oberon:

Oberon backend
==============

Setting the Kconfig option :kconfig:`CONFIG_CC3XX_OBERON` enables legacy crypto support using :ref:`nrf_oberon_readme`


.. _nrf_security_backends_orig_mbedtls:

Original Mbed TLS backend
=========================

The Original Mbed TLS backend is no longer available as a configuration option, and is only used if any of the enabled backends does not support a specific cryptographic algorithm or feature.



AES configuration
*****************

The AES core is enabled with the Kconfig option :kconfig:`CONFIG_MBEDTLS_AES_C`.

This enables AES ECB cipher mode and allows the ciphers and modes CTR, OFB, CFB, CBC, XTS, CMAC, CCM/CCM*, and GCM to be configured.

Feature support
===============

+-------------+-------------------+-------------+
| Cipher mode | Backend           | Key size    |
+=============+===================+=============+
| ECB         | cc310             | 128-bit key |
|             +-------------------+-------------+
|             | cc312             | 128-bit key |
|             |                   +-------------+
|             |                   | 192-bit key |
|             |                   +-------------+
|             |                   | 256-bit key |
|             +-------------------+-------------+
|             | nrf_oberon        | 128-bit key |
|             |                   +-------------+
|             |                   | 192-bit key |
|             |                   +-------------+
|             |                   | 256-bit key |
+-------------+-------------------+-------------+

.. note::
   * The :ref:`nrf_security_backends_oberon` uses some functionality from Original Mbed TLS for AES operations.

AES cipher configuration
************************

AES cipher modes can be configured by setting Kconfig variables in the following table:

+--------------+---------------------------------------------+----------------------------------------+
| Cipher mode  | Configurations                              | Note                                   |
+==============+=============================================+========================================+
| CTR          | :kconfig:`CONFIG_MBEDTLS_CIPHER_MODE_CTR`   |                                        |
+--------------+---------------------------------------------+----------------------------------------+
| CBC          | :kconfig:`CONFIG_MBEDTLS_CIPHER_MODE_CBC`   |                                        |
+--------------+---------------------------------------------+----------------------------------------+
| CFB          | :kconfig:`CONFIG_MBEDTLS_CIPHER_MODE_CFB`   | nrf_oberon only                        |
+--------------+---------------------------------------------+----------------------------------------+
| OFB          | :kconfig:`CONFIG_MBEDTLS_CIPHER_MODE_OFB`   | nrf_oberon only                        |
+--------------+---------------------------------------------+----------------------------------------+
| XTS          | :kconfig:`CONFIG_MBEDTLS_CIPHER_MODE_XTS`   | nrf_oberon only                        |
+--------------+---------------------------------------------+----------------------------------------+

.. note::
   * AES cipher modes are dependent on enabling AES core support according to `AES configuration`_.

Feature support
===============

+-------------+-------------------+-------------+-----------------------+
| Cipher mode | Backend           | Key size    | Note                  |
+=============+===================+=============+=======================+
| CTR         | cc310             | 128-bit key |                       |
|             +-------------------+-------------+-----------------------+
|             | cc312             | 128-bit key |                       |
|             |                   +-------------+-----------------------+
|             |                   | 192-bit key |                       |
|             |                   +-------------+-----------------------+
|             |                   | 256-bit key |                       |
|             +-------------------+-------------+-----------------------+
|             | nrf_oberon        | 128-bit key |                       |
|             |                   +-------------+-----------------------+
|             |                   | 192-bit key |                       |
|             |                   +-------------+-----------------------+
|             |                   | 256-bit key |                       |
+-------------+-------------------+-------------+-----------------------+
| CBC         | cc310             | 128-bit key |                       |
|             +-------------------+-------------+-----------------------+
|             | cc312             | 128-bit key |                       |
|             |                   +-------------+-----------------------+
|             |                   | 192-bit key |                       |
|             |                   +-------------+-----------------------+
|             |                   | 256-bit key |                       |
|             +-------------------+-------------+-----------------------+
|             | nrf_oberon        | 128-bit key |                       |
|             |                   +-------------+-----------------------+
|             |                   | 192-bit key |                       |
|             |                   +-------------+-----------------------+
|             |                   | 256-bit key |                       |
+-------------+-------------------+-------------+-----------------------+
| CFB         | cc310             | N/A         | Backend not supported |
|             +-------------------+-------------+-----------------------+
|             | cc312             | N/A         | Backend not supported |
|             +-------------------+-------------+-----------------------+
|             | nrf_oberon        | 128-bit key |                       |
|             |                   +-------------+-----------------------+
|             |                   | 192-bit key |                       |
|             |                   +-------------+-----------------------+
|             |                   | 256-bit key |                       |
+-------------+-------------------+-------------+-----------------------+
| OFB         | cc310             | N/A         | Backend not supported |
|             +-------------------+-------------+-----------------------+
|             | cc312             | N/A         | Backend not supported |
|             +-------------------+-------------+-----------------------+
|             | nrf_oberon        | 128-bit key |                       |
|             |                   +-------------+-----------------------+
|             |                   | 192-bit key |                       |
|             |                   +-------------+-----------------------+
|             |                   | 256-bit key |                       |
+-------------+-------------------+-------------+-----------------------+
| XTS         | cc310             | N/A         | Backend not supported |
|             +-------------------+-------------+-----------------------+
|             | cc312             | N/A         | Backend not supported |
|             +-------------------+-------------+-----------------------+
|             | nrf_oberon        | 128-bit key |                       |
|             |                   +-------------+-----------------------+
|             |                   | 192-bit key |                       |
|             |                   +-------------+-----------------------+
|             |                   | 256-bit key |                       |
+-------------+-------------------+-------------+-----------------------+

CMAC configuration
******************

Cipher-based Message Authentication Code (CMAC) support can be configured by setting the :kconfig:`CONFIG_MBEDTLS_CMAC_C` Kconfig variable.

Feature support
===============

+-----------+-------------------+-------------+
| Algorithm | Backend           | Key size    |
+===========+===================+=============+
| CMAC      | cc310             | 128-bit key |
|           +-------------------+-------------+
|           | cc312             | 128-bit key |
|           |                   +-------------+
|           |                   | 192-bit key |
|           |                   +-------------+
|           |                   | 256-bit key |
|           +-------------------+-------------+
|           | nrf_oberon        | 128-bit key |
|           |                   +-------------+
|           |                   | 192-bit key |
|           |                   +-------------+
|           |                   | 256-bit key |
+-----------+-------------------+-------------+


AEAD configurations
*******************

Authenticated Encryption with Associated Data (AEAD) can be configured by setting Kconfig variables in the following table:

+--------------+-----------------------------------------+-----------------------------------------+
| AEAD cipher  | Configurations                          | Note                                    |
+==============+=========================================+=========================================+
| AES CCM/CCM* | :kconfig:`CONFIG_MBEDTLS_CCM_C`         |                                         |
+--------------+-----------------------------------------+-----------------------------------------+
| AES GCM      | :kconfig:`CONFIG_MBEDTLS_GCM_C`         | nrf_oberon or cc312                     |
+--------------+-----------------------------------------+-----------------------------------------+
| ChaCha20     | :kconfig:`CONFIG_MBEDTLS_CHACHA20_C`    |                                         |
+--------------+-----------------------------------------+-----------------------------------------+
| Poly1305     | :kconfig:`CONFIG_MBEDTLS_POLY1305_C`    |                                         |
+--------------+-----------------------------------------+-----------------------------------------+
| ChaCha-Poly  | :kconfig:`CONFIG_MBEDTLS_CHACHAPOLY_C`  | Requires `Poly1305` and `ChaCha20`      |
+--------------+-----------------------------------------+-----------------------------------------+

.. note::
   * AEAD AES cipher modes are dependent on enabling AES core support according to `AES configuration`_.
   * When Arm CryptoCell cc310 backend is used, AES GCM is provided by original Mbed TLS implementation.
   * The ChaCha-Poly implemented by the Arm CryptoCell cc3xx backend does not support incremental operations.
   * The ChaCha-Poly implemented by the :ref:`nrf_security_backends_cc3xx` does not support incremental operations.

Feature support
===============

+--------------+-------------------+-------------+----------------------------------------------------------------------+
| AEAD cipher  | Backend           | Key size    | Note                                                                 |
+==============+===================+=============+======================================================================+
| AES CCM/CCM* | cc310             | 128-bit key |                                                                      |
|              +-------------------+-------------+----------------------------------------------------------------------+
|              | cc312             | 128-bit key |                                                                      |
|              |                   +-------------+----------------------------------------------------------------------+
|              |                   | 192-bit key |                                                                      |
|              |                   +-------------+----------------------------------------------------------------------+
|              |                   | 256-bit key |                                                                      |
|              +-------------------+-------------+----------------------------------------------------------------------+
|              | nrf_oberon        | 128-bit key |                                                                      |
|              |                   +-------------+----------------------------------------------------------------------+
|              |                   | 192-bit key |                                                                      |
|              |                   +-------------+----------------------------------------------------------------------+
|              |                   | 256-bit key |                                                                      |
+--------------+-------------------+-------------+----------------------------------------------------------------------+
| AES GCM      | cc312             | 128-bit key |                                                                      |
|              |                   +-------------+----------------------------------------------------------------------+
|              |                   | 192-bit key |                                                                      |
|              |                   +-------------+----------------------------------------------------------------------+
|              |                   | 256-bit key |                                                                      |
|              +-------------------+-------------+----------------------------------------------------------------------+
|              | nrf_oberon        | 128-bit key |                                                                      |
|              |                   +-------------+----------------------------------------------------------------------+
|              |                   | 192-bit key |                                                                      |
|              |                   +-------------+----------------------------------------------------------------------+
|              |                   | 256-bit key |                                                                      |
+--------------+-------------------+-------------+----------------------------------------------------------------------+
| ChaCha20     | cc3xx             | 256-bit key |                                                                      |
|              +-------------------+-------------+----------------------------------------------------------------------+
|              | nrf_oberon        | 256-bit key |                                                                      |
+--------------+-------------------+-------------+----------------------------------------------------------------------+
| Poly1305     | cc3xx             | 256-bit key |                                                                      |
|              +-------------------+-------------+----------------------------------------------------------------------+
|              | nrf_oberon        | 256-bit key |                                                                      |
+--------------+-------------------+-------------+----------------------------------------------------------------------+
| ChaCha-Poly  | cc3xx             | 256-bit key | The ChaCha-Poly implementation in :ref:`nrf_security_backends_cc3xx` |
|              |                   |             | does not support incremental operations.                             |
|              +-------------------+-------------+----------------------------------------------------------------------+
|              | nrf_oberon        | 256-bit key |                                                                      |
+--------------+-------------------+-------------+----------------------------------------------------------------------+

DHM configurations
******************

Diffie-Hellman-Merkle (DHM) support can be configured by setting the :kconfig:`CONFIG_MBEDTLS_DHM_C` Kconfig variable.

Feature support
===============

+-----------+-------------------+----------------------+-----------------------+
| Algorithm | Backend           | Key size             | Note                  |
+===========+===================+======================+=======================+
| DHM       | cc3xx             | Limited to 2048 bits |                       |
|           +-------------------+----------------------+-----------------------+
|           | nrf_oberon        | N/A                  | Backend not supported |
+-----------+-------------------+----------------------+-----------------------+

.. note::
   The :ref:`nrf_security_backends_oberon` uses functionality from Original Mbed TLS for DHM operations.

ECC configurations
******************

Elliptic Curve Cryptography (ECC) configuration provides support for Elliptic Curve over GF(p).

ECC core support can be configured by setting the :kconfig:`CONFIG_MBEDTLS_ECP_C` Kconfig variable.

Enabling :kconfig:`CONFIG_MBEDTLS_ECP_C` will activate configuration options that depend upon ECC, such as ECDH, ECDSA, ECJPAKE, and a selection of ECC curves to support in the system.

Feature support
===============

+-----------+-------------------+-------------+------------+
| Algorithm | Backend           | Curve group | Curve type |
+===========+===================+=============+============+
| ECP       | cc3xx             | NIST        | secp192r1  |
|           |                   |             +------------+
|           |                   |             | secp224r1  |
|           |                   |             +------------+
|           |                   |             | secp256r1  |
|           |                   |             +------------+
|           |                   |             | secp384r1  |
|           |                   |             +------------+
|           |                   |             | secp521r1  |
|           |                   +-------------+------------+
|           |                   | Koblitz     | secp192k1  |
|           |                   |             +------------+
|           |                   |             | secp224k1  |
|           |                   |             +------------+
|           |                   |             | secp256k1  |
|           |                   +-------------+------------+
|           |                   | Curve25519  | Curve25519 |
|           +-------------------+-------------+------------+
|           | nrf_oberon        | NIST        | secp256r1  |
|           |                   |             +------------+
|           |                   |             | secp224r1  |
|           |                   +-------------+------------+
|           |                   | Curve25519  | Curve25519 |
+-----------+-------------------+-------------+------------+

ECDH configurations
*******************

Elliptic Curve Diffie-Hellman (ECDH) support can be configured by setting the :kconfig:`CONFIG_MBEDTLS_ECDH_C` Kconfig variable.

+--------------+--------------------------------------+
| Algorithm    | Configurations                       |
+==============+======================================+
| ECDH         | :kconfig:`CONFIG_MBEDTLS_ECDH_C`     |
+--------------+--------------------------------------+

.. note::
   * ECDH support depends upon `ECC Configurations`_ being enabled.
   * The :ref:`nrf_cc3xx_mbedcrypto_readme` does not integrate on ECP layer.
     Only the top-level APIs for ECDH are replaced.

Feature support
===============

+-----------+-------------------+-------------+------------+
| Algorithm | Backend           | Curve group | Curve type |
+===========+===================+=============+============+
| ECDH      | cc3xx             | NIST        | secp192r1  |
|           |                   |             +------------+
|           |                   |             | secp224r1  |
|           |                   |             +------------+
|           |                   |             | secp256r1  |
|           |                   |             +------------+
|           |                   |             | secp384r1  |
|           |                   |             +------------+
|           |                   |             | secp521r1  |
|           |                   +-------------+------------+
|           |                   | Koblitz     | secp192k1  |
|           |                   |             +------------+
|           |                   |             | secp224k1  |
|           |                   |             +------------+
|           |                   |             | secp256k1  |
|           |                   +-------------+------------+
|           |                   | Curve25519  | Curve25519 |
|           +-------------------+-------------+------------+
|           | nrf_oberon        | NIST        | secp256r1  |
|           |                   |             +------------+
|           |                   |             | secp224r1  |
|           |                   +-------------+------------+
|           |                   | Curve25519  | Curve25519 |
+-----------+-------------------+-------------+------------+

ECDSA configurations
********************

Elliptic Curve Digital Signature Algorithm (ECDSA) support can be configured be configured by setting the :kconfig:`CONFIG_MBEDTLS_ECDSA_C` Kconfig variable.

+--------------+---------------------------------------+
| Algorithm    | Configurations                        |
+==============+=======================================+
| ECDSA        | :kconfig:`CONFIG_MBEDTLS_ECDSA_C`     |
+--------------+---------------------------------------+

.. note::
   * ECDSA support depends upon `ECC Configurations`_ being enabled.
   * The :ref:`nrf_cc3xx_mbedcrypto_readme` does not integrate on ECP layer.
     Only the top-level APIs for ECDSA are replaced.

Feature support
===============

+-----------+-------------------+-------------+------------+
| Algorithm | Backend           | Curve group | Curve type |
+===========+===================+=============+============+
| ECDSA     | cc3xx             | NIST        | secp192r1  |
|           |                   |             +------------+
|           |                   |             | secp224r1  |
|           |                   |             +------------+
|           |                   |             | secp256r1  |
|           |                   |             +------------+
|           |                   |             | secp384r1  |
|           |                   |             +------------+
|           |                   |             | secp521r1  |
|           |                   +-------------+------------+
|           |                   | Koblitz     | secp192k1  |
|           |                   |             +------------+
|           |                   |             | secp224k1  |
|           |                   |             +------------+
|           |                   |             | secp256k1  |
|           |                   +-------------+------------+
|           |                   | Curve25519  | Curve25519 |
|           +-------------------+-------------+------------+
|           | nrf_oberon        | NIST        | secp256r1  |
|           |                   |             +------------+
|           |                   |             | secp224r1  |
|           |                   +-------------+------------+
|           |                   | Curve25519  | Curve25519 |
+-----------+-------------------+-------------+------------+

ECJPAKE configurations
**********************

Elliptic Curve, Password Authenticated Key Exchange by Juggling (ECJPAKE) support can be configured by setting the :kconfig:`CONFIG_MBEDTLS_ECJPAKE_C` Kconfig variable.

+--------------+---------------------------------------+
| Algorithm    | Configurations                        |
+==============+=======================================+
| ECJPAKE      | :kconfig:`CONFIG_MBEDTLS_ECJPAKE_C`   |
+--------------+---------------------------------------+

.. note::
   ECJPAKE support depends upon `ECC Configurations`_ being enabled.

Feature support
===============

+-----------+-------------------+-------------+------------+
| Algorithm | Backend           | Curve group | Curve type |
+===========+===================+=============+============+
| ECJPAKE   | cc3xx             | NIST        | secp256r1  |
|           +-------------------+-------------+------------+
|           | nrf_oberon        | NIST        | secp256r1  |
+-----------+-------------------+-------------+------------+


.. _nrf_security_backend_config_ecc_curves:

ECC curves configurations
*************************

It is possible to configure the curves that should be supported in the system depending on the backend selected.

The following table shows the curves that can be enabled.

+-----------------------------+-----------------------------------------------------+--------------------------+
| Curve                       | Configurations                                      | Note                     |
+=============================+=====================================================+==========================+
| NIST secp192r1              | :kconfig:`CONFIG_MBEDTLS_ECP_DP_SECP192R1_ENABLED`  |                          |
+-----------------------------+-----------------------------------------------------+--------------------------+
| NIST secp224r1              | :kconfig:`CONFIG_MBEDTLS_ECP_DP_SECP224R1_ENABLED`  |                          |
+-----------------------------+-----------------------------------------------------+--------------------------+
| NIST secp256r1              | :kconfig:`CONFIG_MBEDTLS_ECP_DP_SECP256R1_ENABLED`  |                          |
+-----------------------------+-----------------------------------------------------+--------------------------+
| NIST secp384r1              | :kconfig:`CONFIG_MBEDTLS_ECP_DP_SECP384R1_ENABLED`  |                          |
+-----------------------------+-----------------------------------------------------+--------------------------+
| NIST secp521r1              | :kconfig:`CONFIG_MBEDTLS_ECP_DP_SECP521R1_ENABLED`  |                          |
+-----------------------------+-----------------------------------------------------+--------------------------+
| Koblitz secp192k1           | :kconfig:`CONFIG_MBEDTLS_ECP_DP_SECP192K1_ENABLED`  |                          |
+-----------------------------+-----------------------------------------------------+--------------------------+
| Koblitz secp224k1           | :kconfig:`CONFIG_MBEDTLS_ECP_DP_SECP224K1_ENABLED`  |                          |
+-----------------------------+-----------------------------------------------------+--------------------------+
| Koblitz secp256k1           | :kconfig:`CONFIG_MBEDTLS_ECP_DP_SECP256K1_ENABLED`  |                          |
+-----------------------------+-----------------------------------------------------+--------------------------+
| Curve25519                  | :kconfig:`CONFIG_MBEDTLS_ECP_DP_CURVE25519_ENABLED` |                          |
+-----------------------------+-----------------------------------------------------+--------------------------+

.. note::
   * The :ref:`nrf_oberon_readme` only supports ECC curve secp224r1 and secp256r1.
   * Choosing the nrf_oberon backend does not allow enabling the rest of the ECC curve types.


RSA configurations
******************

Rivest-Shamir-Adleman (RSA) support can be configured by setting the :kconfig:`CONFIG_MBEDTLS_RSA_C` Kconfig variable.

Feature support
===============

+-----------+-------------------+----------------------+-----------------------+
| Algorithm | Backend           | Key size             | Note                  |
+===========+===================+======================+=======================+
| RSA       | cc3xx             | Limited to 2048 bits |                       |
|           +-------------------+----------------------+-----------------------+
|           | nrf_oberon        | N/A                  | Backend not supported |
+-----------+-------------------+----------------------+-----------------------+

.. note::
   The :ref:`nrf_security_backends_oberon` uses functionality from Original Mbed TLS for RSA operations.

Secure Hash configurations
**************************

The Secure Hash algorithms can be configured by setting Kconfig variables in the following table:

+--------------+--------------------+--------------------------------------+
| Algorithm    | Support            | Backend selection                    |
+==============+====================+======================================+
| SHA-1        |                    | :kconfig:`CONFIG_MBEDTLS_SHA1_C`     |
+--------------+--------------------+--------------------------------------+
| SHA-224      |                    | :kconfig:`CONFIG_MBEDTLS_SHA224_C`   |
+--------------+--------------------+--------------------------------------+
| SHA-256      |                    | :kconfig:`CONFIG_MBEDTLS_SHA256_C`   |
+--------------+--------------------+--------------------------------------+
| SHA-384      |                    | :kconfig:`CONFIG_MBEDTLS_SHA384_C`   |
+--------------+--------------------+--------------------------------------+
| SHA-512      |                    | :kconfig:`CONFIG_MBEDTLS_SHA512_C`   |
+--------------+--------------------+--------------------------------------+

Feature support
===============

+-----------+--------------------+----------------------------------------+
| Algorithm | Supported backends | Note                                   |
+===========+====================+========================================+
| SHA-1     | cc3xx              |                                        |
|           +--------------------+                                        |
|           | nrf_oberon         |                                        |
+-----------+--------------------+----------------------------------------+
| SHA-224   | cc3xx              | SHA-224 must be enabled when enabling  |
|           +--------------------+ SHA-256                                |
|           | nrf_oberon         |                                        |
+-----------+--------------------+----------------------------------------+
| SHA-256   | cc3xx              |                                        |
|           +--------------------+                                        |
|           | nrf_oberon         |                                        |
+-----------+--------------------+----------------------------------------+
| SHA-384   | cc3xx              |                                        |
|           +--------------------+                                        |
|           | nrf_oberon         |                                        |
+-----------+--------------------+----------------------------------------+
| SHA-512   | cc3xx              |                                        |
|           +--------------------+                                        |
|           | nrf_oberon         |                                        |
+-----------+--------------------+----------------------------------------+
