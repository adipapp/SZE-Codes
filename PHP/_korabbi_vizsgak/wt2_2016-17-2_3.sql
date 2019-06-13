-- phpMyAdmin SQL Dump
-- version 4.6.6
-- https://www.phpmyadmin.net/
--
-- Gép: localhost
-- Létrehozás ideje: 2017. Jún 05. 08:19
-- Kiszolgáló verziója: 5.5.54-0+deb8u1
-- PHP verzió: 7.0.15-1~dotdeb+8.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Adatbázis: `hallgatok`
--

-- --------------------------------------------------------

--
-- Tábla szerkezet ehhez a táblához `festek`
--

CREATE TABLE `festek` (
  `id` int(11) NOT NULL COMMENT 'Egyedi azonosító',
  `nev` varchar(64) COLLATE utf8_hungarian_ci NOT NULL COMMENT 'A festék neve',
  `kiadossag` float NOT NULL COMMENT 'Kiadósság, m^2/liter'
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_hungarian_ci;

--
-- A tábla adatainak kiíratása `festek`
--

INSERT INTO `festek` (`id`, `nev`, `kiadossag`) VALUES
(1, 'Polifarbe diszperziós falfesték', 5.5),
(2, 'DULUX ACRYL MATT FEHÉR', 12),
(3, 'HÉRA BELSŐ FALFESTÉK', 9),
(4, 'INNTALER PRÉMIUM', 7),
(5, 'POLIFARBE PLATINUM FEHÉR', 17.5);

--
-- Indexek a kiírt táblákhoz
--

--
-- A tábla indexei `festek`
--
ALTER TABLE `festek`
  ADD PRIMARY KEY (`id`);

--
-- A kiírt táblák AUTO_INCREMENT értéke
--

--
-- AUTO_INCREMENT a táblához `festek`
--
ALTER TABLE `festek`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT COMMENT 'Egyedi azonosító', AUTO_INCREMENT=6;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
