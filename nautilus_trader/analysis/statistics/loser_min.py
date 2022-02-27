# -------------------------------------------------------------------------------------------------
#  Copyright (C) 2015-2022 Nautech Systems Pty Ltd. All rights reserved.
#  https://nautechsystems.io
#
#  Licensed under the GNU Lesser General Public License Version 3.0 (the "License");
#  You may not use this file except in compliance with the License.
#  You may obtain a copy of the License at https://www.gnu.org/licenses/lgpl-3.0.en.html
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.
# -------------------------------------------------------------------------------------------------

from typing import Any, Optional

import numpy as np
import pandas as pd

from nautilus_trader.analysis.statistic import PerformanceStatistic
from nautilus_trader.model.currency import Currency
from nautilus_trader.model.objects import Money


class MinLoser(PerformanceStatistic):
    """
    Calculates the minimum loser from a series of PnLs.
    """

    @staticmethod
    def format_stat_with_currency(stat: Any, currency: Currency) -> str:
        return str(Money(stat, currency))

    @staticmethod
    def calculate_from_realized_pnls(
        currency: Currency,
        realized_pnls: pd.Series[float],
    ) -> Optional[Any]:
        # Preconditions
        if realized_pnls is None or realized_pnls.empty:
            return 0.0

        # Calculate statistic
        losers = [x for x in realized_pnls if x <= 0.0]
        if not losers:
            return 0.0

        return max(np.asarray(losers, dtype=np.float64))  # max is least loser
