/**
 * @file payment/payment.h
 * @brief Master header file for the payment module.
 * @note This header includes all the main headers for the payment module.
 */

#ifndef PAYMENT_PAYMENT_H_
#define PAYMENT_PAYMENT_H_

#include "payment/payment_methods/payment_method_interfaces.h"
#include "payment/payment_methods/cash_payment/cash_payment.h"
#include "payment/payment_methods/card_payment/card_payment.h"
#include "payment/payment_methods/card_payment/online_card_payment.h"
#include "payment/account.h"
#include "payment/context.h"
#include "payment/ticket.h"
#include "payment/transaction.h"

#endif  // PAYMENT_PAYMENT_H_