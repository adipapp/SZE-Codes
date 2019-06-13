-- phpMyAdmin SQL Dump
-- version 4.6.6
-- https://www.phpmyadmin.net/
--
-- Gép: localhost
-- Létrehozás ideje: 2017. Máj 24. 15:38
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
-- Tábla szerkezet ehhez a táblához `hitachi`
--

CREATE TABLE `hitachi` (
  `id` int(11) NOT NULL COMMENT 'Egyedi azonosító',
  `name` varchar(255) COLLATE utf8_hungarian_ci NOT NULL,
  `Cdefinition` varchar(255) COLLATE utf8_hungarian_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_hungarian_ci;

--
-- A tábla adatainak kiíratása `hitachi`
--

INSERT INTO `hitachi` (`id`, `name`, `Cdefinition`) VALUES
(1, 'myChar', 'unsigned char myChar[8] = { 10, 0, 17, 17, 17, 19, 13 };');

--
-- Indexek a kiírt táblákhoz
--

--
-- A tábla indexei `hitachi`
--
ALTER TABLE `hitachi`
  ADD PRIMARY KEY (`id`);

--
-- A kiírt táblák AUTO_INCREMENT értéke
--

--
-- AUTO_INCREMENT a táblához `hitachi`
--
ALTER TABLE `hitachi`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT COMMENT 'Egyedi azonosító', AUTO_INCREMENT=2;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
